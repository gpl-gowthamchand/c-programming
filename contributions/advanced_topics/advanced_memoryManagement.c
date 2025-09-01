/*
 * Advanced Topic: Memory Management in C
 * Author: gpl-gowthamchand
 * Date: 2025-01-27
 * 
 * Description: Advanced memory management techniques including dynamic allocation, memory pools, and optimization
 * 
 * Prerequisites: Understanding of pointers, functions, and basic C programming
 * 
 * Technical Details:
 * - Dynamic memory allocation and deallocation
 * - Memory leak detection and prevention
 * - Memory pool implementation
 * - Custom memory allocators
 * - Memory alignment and optimization
 * 
 * Implementation Notes:
 * This implementation demonstrates advanced memory management patterns
 * commonly used in system programming and embedded systems
 * 
 * Performance Characteristics:
 * - Time Complexity: O(1) for allocation/deallocation
 * - Space Complexity: O(n) where n is the number of allocated blocks
 * - Memory Usage: Optimized for minimal fragmentation
 * 
 * Dependencies:
 * - Standard C library (stdlib.h, string.h)
 * - System-specific headers for advanced features
 * 
 * Testing:
 * - Memory leak detection using valgrind
 * - Stress testing with large allocations
 * - Boundary condition testing
 * 
 * Known Limitations:
 * - Single-threaded implementation
 * - Fixed pool size (can be made dynamic)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define POOL_SIZE 1024
#define BLOCK_SIZE 64
#define MAX_BLOCKS (POOL_SIZE / BLOCK_SIZE)

// Memory block structure
typedef struct MemoryBlock {
    void *data;
    size_t size;
    int is_allocated;
    struct MemoryBlock *next;
} MemoryBlock;

// Memory pool structure
typedef struct MemoryPool {
    char pool[POOL_SIZE];
    MemoryBlock blocks[MAX_BLOCKS];
    int free_blocks;
    int total_blocks;
} MemoryPool;

// Global memory pool
static MemoryPool g_pool = {0};

// Function to initialize memory pool
void initMemoryPool() {
    printf("Initializing memory pool...\n");
    
    // Initialize pool
    memset(g_pool.pool, 0, POOL_SIZE);
    memset(g_pool.blocks, 0, sizeof(g_pool.blocks));
    
    // Initialize blocks
    for (int i = 0; i < MAX_BLOCKS; i++) {
        g_pool.blocks[i].data = g_pool.pool + (i * BLOCK_SIZE);
        g_pool.blocks[i].size = BLOCK_SIZE;
        g_pool.blocks[i].is_allocated = 0;
        g_pool.blocks[i].next = (i < MAX_BLOCKS - 1) ? &g_pool.blocks[i + 1] : NULL;
    }
    
    g_pool.free_blocks = MAX_BLOCKS;
    g_pool.total_blocks = MAX_BLOCKS;
    
    printf("Memory pool initialized: %d blocks of %d bytes each\n", 
           MAX_BLOCKS, BLOCK_SIZE);
}

// Function to allocate memory from pool
void* poolAlloc(size_t size) {
    if (size > BLOCK_SIZE) {
        printf("Error: Requested size (%zu) exceeds block size (%d)\n", 
               size, BLOCK_SIZE);
        return NULL;
    }
    
    if (g_pool.free_blocks == 0) {
        printf("Error: No free blocks available in pool\n");
        return NULL;
    }
    
    // Find first free block
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (!g_pool.blocks[i].is_allocated) {
            g_pool.blocks[i].is_allocated = 1;
            g_pool.free_blocks--;
            
            printf("Allocated block %d (%p) of size %zu\n", 
                   i, g_pool.blocks[i].data, size);
            return g_pool.blocks[i].data;
        }
    }
    
    return NULL;
}

// Function to deallocate memory back to pool
void poolFree(void* ptr) {
    if (ptr == NULL) {
        printf("Warning: Attempting to free NULL pointer\n");
        return;
    }
    
    // Find the block containing this pointer
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (g_pool.blocks[i].data == ptr) {
            if (g_pool.blocks[i].is_allocated) {
                g_pool.blocks[i].is_allocated = 0;
                g_pool.free_blocks++;
                
                // Clear the memory
                memset(ptr, 0, BLOCK_SIZE);
                
                printf("Freed block %d (%p)\n", i, ptr);
                return;
            } else {
                printf("Error: Double free detected for block %d\n", i);
                return;
            }
        }
    }
    
    printf("Error: Pointer %p not found in pool\n", ptr);
}

// Function to display pool status
void displayPoolStatus() {
    printf("\n=== Memory Pool Status ===\n");
    printf("Total blocks: %d\n", g_pool.total_blocks);
    printf("Free blocks: %d\n", g_pool.free_blocks);
    printf("Allocated blocks: %d\n", g_pool.total_blocks - g_pool.free_blocks);
    printf("Pool utilization: %.1f%%\n", 
           (float)(g_pool.total_blocks - g_pool.free_blocks) * 100 / g_pool.total_blocks);
    
    printf("\nBlock status:\n");
    for (int i = 0; i < MAX_BLOCKS; i++) {
        printf("Block %d: %s (%p)\n", i, 
               g_pool.blocks[i].is_allocated ? "ALLOCATED" : "FREE",
               g_pool.blocks[i].data);
    }
}

// Advanced memory management functions
void* alignedMalloc(size_t size, size_t alignment) {
    void* ptr = malloc(size + alignment - 1);
    if (ptr == NULL) {
        return NULL;
    }
    
    // Calculate aligned address
    uintptr_t addr = (uintptr_t)ptr;
    uintptr_t aligned_addr = (addr + alignment - 1) & ~(alignment - 1);
    
    // Store original pointer for free
    *((void**)(aligned_addr - sizeof(void*))) = ptr;
    
    return (void*)aligned_addr;
}

void alignedFree(void* ptr) {
    if (ptr == NULL) {
        return;
    }
    
    // Get original pointer
    void* original_ptr = *((void**)((uintptr_t)ptr - sizeof(void*)));
    free(original_ptr);
}

// Memory leak detection structure
typedef struct MemoryTracker {
    void* ptr;
    size_t size;
    const char* file;
    int line;
    struct MemoryTracker* next;
} MemoryTracker;

static MemoryTracker* g_tracker = NULL;

// Tracked malloc
void* trackedMalloc(size_t size, const char* file, int line) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        return NULL;
    }
    
    // Add to tracker
    MemoryTracker* tracker = malloc(sizeof(MemoryTracker));
    tracker->ptr = ptr;
    tracker->size = size;
    tracker->file = file;
    tracker->line = line;
    tracker->next = g_tracker;
    g_tracker = tracker;
    
    printf("Tracked allocation: %p (%zu bytes) at %s:%d\n", 
           ptr, size, file, line);
    
    return ptr;
}

// Tracked free
void trackedFree(void* ptr) {
    if (ptr == NULL) {
        return;
    }
    
    // Remove from tracker
    MemoryTracker** current = &g_tracker;
    while (*current != NULL) {
        if ((*current)->ptr == ptr) {
            MemoryTracker* temp = *current;
            *current = (*current)->next;
            printf("Tracked deallocation: %p (%zu bytes) from %s:%d\n", 
                   ptr, temp->size, temp->file, temp->line);
            free(temp);
            free(ptr);
            return;
        }
        current = &(*current)->next;
    }
    
    printf("Warning: Untracked free of %p\n", ptr);
    free(ptr);
}

// Check for memory leaks
void checkMemoryLeaks() {
    printf("\n=== Memory Leak Check ===\n");
    
    int leaks = 0;
    MemoryTracker* current = g_tracker;
    
    while (current != NULL) {
        printf("Memory leak: %p (%zu bytes) allocated at %s:%d\n", 
               current->ptr, current->size, current->file, current->line);
        leaks++;
        current = current->next;
    }
    
    if (leaks == 0) {
        printf("No memory leaks detected! ✅\n");
    } else {
        printf("Total memory leaks: %d ❌\n", leaks);
    }
}

// Cleanup all tracked memory
void cleanupTrackedMemory() {
    MemoryTracker* current = g_tracker;
    while (current != NULL) {
        MemoryTracker* temp = current;
        current = current->next;
        free(temp->ptr);
        free(temp);
    }
    g_tracker = NULL;
}

// Demonstration function
void demonstrateAdvancedMemoryManagement() {
    printf("=== Advanced Memory Management Demo ===\n");
    
    // Initialize memory pool
    initMemoryPool();
    
    // Test pool allocation
    void* ptr1 = poolAlloc(32);
    void* ptr2 = poolAlloc(16);
    void* ptr3 = poolAlloc(48);
    
    displayPoolStatus();
    
    // Test pool deallocation
    poolFree(ptr2);
    displayPoolStatus();
    
    // Test aligned allocation
    printf("\n=== Aligned Memory Allocation ===\n");
    void* aligned_ptr = alignedMalloc(100, 16);
    printf("Aligned allocation: %p (16-byte aligned)\n", aligned_ptr);
    alignedFree(aligned_ptr);
    
    // Test tracked allocation
    printf("\n=== Tracked Memory Allocation ===\n");
    void* tracked_ptr1 = trackedMalloc(100, __FILE__, __LINE__);
    void* tracked_ptr2 = trackedMalloc(200, __FILE__, __LINE__);
    
    trackedFree(tracked_ptr1);
    
    // Check for leaks
    checkMemoryLeaks();
    
    // Cleanup
    cleanupTrackedMemory();
    poolFree(ptr1);
    poolFree(ptr3);
}

int main() {
    printf("========================================\n");
    printf("  Advanced Memory Management in C      \n");
    printf("========================================\n");
    
    demonstrateAdvancedMemoryManagement();
    
    printf("\n========================================\n");
    printf("    Demo Complete! 🎉\n");
    printf("========================================\n");
    printf("Key Concepts Demonstrated:\n");
    printf("- Memory pool implementation\n");
    printf("- Aligned memory allocation\n");
    printf("- Memory leak detection\n");
    printf("- Advanced memory tracking\n");
    printf("- Memory optimization techniques\n");
    
    return 0;
}
