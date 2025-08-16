# Installation Guide for Fedora Workstation 42

> **Note**: This is my personal setup and recommended installation method for VS Code on Fedora Workstation 42. I've tested this approach and found it to be the most reliable way to get VS Code running on this distribution.

This guide covers the installation of Microsoft Visual Studio Code on Fedora Workstation 42, which is the recommended development environment for C programming.

## Method 1: Official Repository Installation (Recommended)

### Step 1: Add Microsoft's Repository

First, import Microsoft's GPG key and add their official repository:

```bash
sudo rpm --import https://packages.microsoft.com/keys/microsoft.asc
sudo sh -c 'echo -e "[code]\nname=Visual Studio Code\nbaseurl=https://packages.microsoft.com/yumrepos/vscode\nenabled=1\ngpgcheck=1\ngpgkey=https://packages.microsoft.com/keys/microsoft.asc" > /etc/yum.repos.d/vscode.repo'
```

### Step 2: Update and Install

Update your package list and install VS Code:

```bash
sudo dnf check-update
sudo dnf install code
```

### Step 3: Launch VS Code

You can now launch VS Code in two ways:

**Option A: Command Line**
```bash
code
```

**Option B: Application Menu**
Search for "Visual Studio Code" in your application menu (Activities → Show Applications)

## Method 2: Flatpak Installation (Alternative)

If you prefer the sandboxed Flatpak version:

### Install via Flatpak
```bash
flatpak install flathub com.visualstudio.code
```

### Run VS Code
```bash
flatpak run com.visualstudio.code
```

## Why VS Code for C Programming?

- **Integrated Terminal**: Built-in terminal for compiling and running C programs
- **C/C++ Extensions**: Excellent support for C programming with IntelliSense
- **Debugging**: Built-in debugger support
- **Git Integration**: Version control directly in the editor
- **Cross-platform**: Consistent experience across different operating systems

## Post-Installation Setup

After installing VS Code, consider installing these extensions for C programming:

1. **C/C++** by Microsoft
2. **C/C++ Extension Pack** by Microsoft
3. **Code Runner** by Jun Han
4. **GitLens** by GitKraken

## System Requirements

- Fedora Workstation 42 (or later)
- At least 1GB of available disk space
- 512MB RAM minimum (1GB recommended)
- Internet connection for initial setup and extensions

## Troubleshooting

If you encounter any issues:

1. **Repository Issues**: Ensure the Microsoft repository was added correctly
2. **Permission Errors**: Check that you have sudo privileges
3. **Flatpak Issues**: Ensure Flatpak is enabled on your system
4. **Launch Problems**: Try launching from terminal to see error messages

## Next Steps

Once VS Code is installed, you can:
- Open your C programming workspace
- Install recommended extensions
- Configure your development environment
- Start writing and compiling C programs
