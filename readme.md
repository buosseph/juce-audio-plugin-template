# Audio Plugin Template

This is a set of files to act as a template for creating audio effect plugins using the JUCE framework. This template also sets up the JUCE GUI editor for the `PluginEditor` class including the inheritance of `Timer` for synchronizing parameters with host values. An optional `PluginParameter` class is included for creating safer parameters with callbacks, which require C++11. You can still use the native JUCE parameter implementations.  

This is more for my personal projects with Juce audio plugins, but hopefully this can help others better understand the JUCE API and as a starting point for setting up their projects.

## Usage

1. Open the Projucer, or the Introjucer, and create a new Audio Plug-in with your target platforms
2. Copy all the files in `Source` and into your JUCE project `Source` folder
  - You may have to save and reopen the Projucer, or Introjucer, for the GUI editor to show up
3. Open your target IDE and compile your project to verify everything works and start designing your plugin!
