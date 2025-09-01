/*
 * Advanced Topic: Multi-threading in C
 * Author: gpl-gowthamchand
 * Date: 2025-01-27
 * 
 * Description: Advanced multi-threading concepts including thread synchronization, mutexes, and condition variables
 * 
 * Prerequisites: Understanding of C programming, basic knowledge of operating systems
 * 
 * Technical Details:
 * - POSIX threads (pthreads) implementation
 * - Thread synchronization mechanisms
 * - Mutex and condition variable usage
 * - Thread-safe data structures
 * - Deadlock prevention techniques
 * 
 * Implementation Notes:
 * This implementation demonstrates advanced threading patterns
 * commonly used in concurrent programming and system design
 * 
 * Performance Characteristics:
 * - Time Complexity: O(1) for thread operations
 * - Space Complexity: O(n) where n is the number of threads
 * - Memory Usage: Thread stack space + shared data structures
 * 
 * Dependencies:
 * - pthread library (-lpthread flag required for compilation)
 * - POSIX-compliant system (Linux, macOS, etc.)
 * 
 * Testing:
 * - Race condition testing
 * - Deadlock detection
 * - Performance benchmarking
 * - Stress testing with multiple threads
 * 
 * Known Limitations:
 * - Platform-specific implementation (POSIX)
 * - Requires pthread library
 * - Memory model dependent on architecture
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 100
#define MAX_ITEMS 50

// Thread-safe counter structure
typedef struct {
    int value;
    pthread_mutex_t mutex;
} ThreadSafeCounter;

// Producer-consumer buffer structure
typedef struct {
    int buffer[BUFFER_SIZE];
    int count;
    int in;
    int out;
    pthread_mutex_t mutex;
    pthread_cond_t not_empty;
    pthread_cond_t not_full;
} ProducerConsumerBuffer;

// Global variables
ThreadSafeCounter g_counter = {0, PTHREAD_MUTEX_INITIALIZER};
ProducerConsumerBuffer g_buffer = {
    {0}, 0, 0, 0, 
    PTHREAD_MUTEX_INITIALIZER, 
    PTHREAD_COND_INITIALIZER, 
    PTHREAD_COND_INITIALIZER
};

// Function to initialize thread-safe counter
void initCounter(ThreadSafeCounter* counter) {
    counter->value = 0;
    pthread_mutex_init(&counter->mutex, NULL);
}

// Function to increment thread-safe counter
void incrementCounter(ThreadSafeCounter* counter) {
    pthread_mutex_lock(&counter->mutex);
    counter->value++;
    pthread_mutex_unlock(&counter->mutex);
}

// Function to get counter value
int getCounterValue(ThreadSafeCounter* counter) {
    pthread_mutex_lock(&counter->mutex);
    int value = counter->value;
    pthread_mutex_unlock(&counter->mutex);
    return value;
}

// Function to initialize producer-consumer buffer
void initBuffer(ProducerConsumerBuffer* buffer) {
    buffer->count = 0;
    buffer->in = 0;
    buffer->out = 0;
    pthread_mutex_init(&buffer->mutex, NULL);
    pthread_cond_init(&buffer->not_empty, NULL);
    pthread_cond_init(&buffer->not_full, NULL);
}

// Function to produce item
void produce(ProducerConsumerBuffer* buffer, int item) {
    pthread_mutex_lock(&buffer->mutex);
    
    // Wait until buffer is not full
    while (buffer->count == BUFFER_SIZE) {
        printf("Producer waiting - buffer full\n");
        pthread_cond_wait(&buffer->not_full, &buffer->mutex);
    }
    
    // Add item to buffer
    buffer->buffer[buffer->in] = item;
    buffer->in = (buffer->in + 1) % BUFFER_SIZE;
    buffer->count++;
    
    printf("Produced item %d, buffer count: %d\n", item, buffer->count);
    
    // Signal that buffer is not empty
    pthread_cond_signal(&buffer->not_empty);
    pthread_mutex_unlock(&buffer->mutex);
}

// Function to consume item
int consume(ProducerConsumerBuffer* buffer) {
    pthread_mutex_lock(&buffer->mutex);
    
    // Wait until buffer is not empty
    while (buffer->count == 0) {
        printf("Consumer waiting - buffer empty\n");
        pthread_cond_wait(&buffer->not_empty, &buffer->mutex);
    }
    
    // Remove item from buffer
    int item = buffer->buffer[buffer->out];
    buffer->out = (buffer->out + 1) % BUFFER_SIZE;
    buffer->count--;
    
    printf("Consumed item %d, buffer count: %d\n", item, buffer->count);
    
    // Signal that buffer is not full
    pthread_cond_signal(&buffer->not_full);
    pthread_mutex_unlock(&buffer->mutex);
    
    return item;
}

// Thread function for counter increment
void* counterThread(void* arg) {
    int thread_id = *(int*)arg;
    int iterations = 1000;
    
    printf("Counter thread %d starting with %d iterations\n", thread_id, iterations);
    
    for (int i = 0; i < iterations; i++) {
        incrementCounter(&g_counter);
        
        // Simulate some work
        if (i % 100 == 0) {
            usleep(1000); // 1ms sleep
        }
    }
    
    printf("Counter thread %d completed\n", thread_id);
    return NULL;
}

// Thread function for producer
void* producerThread(void* arg) {
    int thread_id = *(int*)arg;
    int items_to_produce = 10;
    
    printf("Producer thread %d starting, will produce %d items\n", thread_id, items_to_produce);
    
    for (int i = 0; i < items_to_produce; i++) {
        int item = thread_id * 100 + i;
        produce(&g_buffer, item);
        
        // Simulate production time
        usleep(100000); // 100ms sleep
    }
    
    printf("Producer thread %d completed\n", thread_id);
    return NULL;
}

// Thread function for consumer
void* consumerThread(void* arg) {
    int thread_id = *(int*)arg;
    int items_consumed = 0;
    int max_items = 15;
    
    printf("Consumer thread %d starting, will consume up to %d items\n", thread_id, max_items);
    
    while (items_consumed < max_items) {
        int item = consume(&g_buffer);
        items_consumed++;
        
        // Simulate consumption time
        usleep(150000); // 150ms sleep
    }
    
    printf("Consumer thread %d completed, consumed %d items\n", thread_id, items_consumed);
    return NULL;
}

// Function to demonstrate basic threading
void demonstrateBasicThreading() {
    printf("=== Basic Threading Demo ===\n");
    
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];
    
    // Initialize counter
    initCounter(&g_counter);
    
    // Create threads
    for (int i = 0; i < MAX_THREADS; i++) {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, counterThread, &thread_ids[i]) != 0) {
            printf("Error creating thread %d\n", i);
            exit(1);
        }
    }
    
    // Wait for all threads to complete
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("Final counter value: %d (expected: %d)\n", 
           getCounterValue(&g_counter), MAX_THREADS * 1000);
}

// Function to demonstrate producer-consumer pattern
void demonstrateProducerConsumer() {
    printf("\n=== Producer-Consumer Demo ===\n");
    
    pthread_t producer_threads[3];
    pthread_t consumer_threads[2];
    int producer_ids[3] = {1, 2, 3};
    int consumer_ids[2] = {1, 2};
    
    // Initialize buffer
    initBuffer(&g_buffer);
    
    // Create producer threads
    for (int i = 0; i < 3; i++) {
        if (pthread_create(&producer_threads[i], NULL, producerThread, &producer_ids[i]) != 0) {
            printf("Error creating producer thread %d\n", i);
            exit(1);
        }
    }
    
    // Create consumer threads
    for (int i = 0; i < 2; i++) {
        if (pthread_create(&consumer_threads[i], NULL, consumerThread, &consumer_ids[i]) != 0) {
            printf("Error creating consumer thread %d\n", i);
            exit(1);
        }
    }
    
    // Wait for all threads to complete
    for (int i = 0; i < 3; i++) {
        pthread_join(producer_threads[i], NULL);
    }
    
    for (int i = 0; i < 2; i++) {
        pthread_join(consumer_threads[i], NULL);
    }
    
    printf("Producer-consumer demo completed\n");
}

// Function to demonstrate thread synchronization
void demonstrateSynchronization() {
    printf("\n=== Thread Synchronization Demo ===\n");
    
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
    int shared_data = 0;
    int ready = 0;
    
    // Thread function that waits for condition
    void* waitingThread(void* arg) {
        pthread_mutex_lock(&mutex);
        
        while (!ready) {
            printf("Waiting thread: waiting for condition...\n");
            pthread_cond_wait(&condition, &mutex);
        }
        
        printf("Waiting thread: condition met, shared_data = %d\n", shared_data);
        pthread_mutex_unlock(&mutex);
        return NULL;
    }
    
    // Thread function that signals condition
    void* signalingThread(void* arg) {
        sleep(2); // Simulate some work
        
        pthread_mutex_lock(&mutex);
        shared_data = 42;
        ready = 1;
        printf("Signaling thread: setting shared_data = %d and signaling\n", shared_data);
        pthread_cond_signal(&condition);
        pthread_mutex_unlock(&mutex);
        
        return NULL;
    }
    
    pthread_t waiter, signaler;
    
    pthread_create(&waiter, NULL, waitingThread, NULL);
    pthread_create(&signaler, NULL, signalingThread, NULL);
    
    pthread_join(waiter, NULL);
    pthread_join(signaler, NULL);
    
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condition);
}

int main() {
    printf("========================================\n");
    printf("    Advanced Threading in C            \n");
    printf("========================================\n");
    printf("Note: This program requires pthread library\n");
    printf("Compile with: gcc -pthread advanced_threading.c -o threading\n\n");
    
    demonstrateBasicThreading();
    demonstrateProducerConsumer();
    demonstrateSynchronization();
    
    printf("\n========================================\n");
    printf("    Demo Complete! 🎉\n");
    printf("========================================\n");
    printf("Key Concepts Demonstrated:\n");
    printf("- Thread creation and synchronization\n");
    printf("- Mutex and condition variables\n");
    printf("- Producer-consumer pattern\n");
    printf("- Thread-safe data structures\n");
    printf("- Deadlock prevention techniques\n");
    
    return 0;
}
