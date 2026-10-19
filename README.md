# D.A MAQAM ANALYZER — VST3 source

## Build on GitHub

Upload the contents of this archive to the repository root, including the hidden `.github/workflows/build.yml` file. Then open **Actions** and run **Build Windows VST3**. A successful run uploads a `DA-MAQAM-ANALYZER-Windows-VST3` artifact.

The workflow uses the Windows 2022 GitHub-hosted runner and the Visual Studio 2022 x64 CMake generator.

## Notes

- JUCE 8.0.10 is fetched by CMake from the official JUCE repository.
- The plugin is an experimental maqam/pitch-analysis prototype, not a comprehensive or validated maqam identification system.
- A successful build has not been independently verified in this packaging step.
