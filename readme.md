# Audio Plugin Template

This is a set of files to act as a template for creating audio effect plugins using the JUCE framework. This template also sets up the JUCE GUI editor for the `PluginEditor` class including the inheritance of `Timer` for synchronizing parameters with host values. A `Parameter` class is included to simplify handling value conversions.

This is more for my personal projects with Juce audio plugins, but hopefully this can help others better understand the JUCE API and as a starting point for setting up their projects.

**This is still very much a work in progress, but should be pretty straight forward to understand.**

## Usage

1. Open the Introjucer and create a new Audio Plug-in with your target platforms
2. Copy all the files in `Source` and into your JUCE project `Source` folder
  - You may have to save and reopen the Introjucer for the GUI editor to show up
3. Open your target IDE and compile your project to verify everything works
