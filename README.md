<div align="center">

# Code Vein Builds

</div>

<!--## What is this program for?-->

> [!NOTE]
> The program is needed for those who do not want to spend hours manually going through different builds and comparing them with each other. This program goes through all
> possible builds in the game and outputs it as a sorted list of builds from best to worst with all the necessary information.

## Launching the program
1. Download the archive (zip/rar) from [latest release page](https://github.com/Gterb102/Code-Vein-Builds/releases/latest)
2. Unpack the contents of the archive
3. Run the executable file `CodeVeinBuilds.exe`

## Using the program
> [!CAUTION]
> Do not edit files in the [`data`](./data) folder, otherwise the program may stop working or do it incorrectly.

When you start the program, you will go to the main menu

There are 4 menu functions:
- `Generate builds` - generates builds

  - Creates a list of builds that match the settings
  - Sorts the list according to the specified parameters
  - Puts the entire list in a file result.txt
  - Suggests displaying part of the list in the console
> [!Important]
> At the moment, sorting is done only by physical damage.

> [!Important]
> The file result.txt it is created during the first generation of builds.
- `Display builds from the latest generation` - display part of the list in the console
- `Generation settings` - settings
  - On the first page, there are settings that affect the number of generated builds
  - On the second page, there are settings that have almost no effect on the number of generated builds
> [!Important]
> You can use the left and right arrows to navigate to another page.
- `Exit` - exiting the program

## Further development

At the moment, the program is far from being completed. There are several plans to add new features and capabilities.

Among them:
1. Additional stats display (withering damage, light, darkness, health points...)
2. Sorting by additional characteristics listed in the last point
3. The ability to select the desired weapon and blood veil in the filter
4. A rating system that will display the position of any build characteristic among other builds.

## Bugs and issues
You can create a request [here](https://github.com/Gterb102/Code-Vein-Builds/issues)

## License
The project is distributed under the terms of the [MIT](https://github.com/Gterb102/Code-Vein-Builds/blob/main/LICENSE) license
