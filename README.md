# mame2010 - AtGames Legends Ultimate Mod

Port of MAME 0.139 for libretro, originally sourced from https://github.com/mamedev/mame/releases/download/mame0139/mame0139s.zip

Includes mods specific to the AtGames Legends Ultimate gaming console.  Original source is found at https://github.com/libretro/mame2010-libretro

## Mods

### Config Saves

Games settings which include controler configured, high scores, and nvram files are persisted into the consoles /userdata/mame2010 folder.  These settings will persist between power cycling the console.

### Samples Support

Samples are supported by adding a game's samples zip file into the ROM Zip in a folder named `samples` (the directory name is case sensitive).  For example, take the game Zaxxon whose ROM Zip file name is `zaxxon.zip` and whose samples file name is also named `zaxxon.zip` (typically samples zip files have the same name as the ROM Zip).  In ROM zip file, you would create a new folder named samples and add the samples `zaxxon.zip` to that folder.  Below is an example of the contents of the ROM Zip:

```
Zaxxon.zip
   - zaxxon.1
   - zaxxon.2
   .
   .
   .
   - zaxxon.u98
   - samples
     - zaxxon.zip
```

### Prebuilt NVRAM Support

Generally games create and modify .nv (nvram) files as needed without issue.  However some games require special sequences to initial these files correctly.  For example, running Simpsons Bowling creates nv file, but a user must go through a series of save states and game resets (the F2 and F3 sequense) to properlly initialize the file so the game loads successfully.  Executing these types of sequense may be very difficult if not impossibly on the Legends console.  However, if you have created a working .nv file using an emulator like Mame or advmame, you can add that .nv file to the ROM zip and have the core explicitly use that .nv file (as opposed to the core creating a new .nv file from scratch).

Similar to adding samples to the ROM zip, custom .nv files are added to the ROM Zip in a folder named `nvram` (case sensitive).  Using the Simpsons Bolwing example above, you would add the pre-created simpbowl.nv file to the ROM zip into the `nvram` folder.  Below is an example of the ROM Zip layout:

```
simpbowl.zip
   - 999a01.73
   - simpbowl.25c
   - zaxxon.u98
   - nvram
     - simpbowl.nv
```

### CHD Support

Some games required an external image file that contains required content for the game to load and run.  CHD files are supported similarly to samples by placing the game's chd file into the ROM Zip in a folder named `chd` (case sensitive).  The core extracts the CHD file and places it into the console /tmp folder and the core loads the CHD content from that directory.  

*NOTE:* CHD files can be very large (sometimes 1 or many gigabytes).  There is limited storage on the console, so it very possible that games with CHD files larger that a couple of hundred megabytes may not load due to insufficient storage.  To be a good neighbor, the core deletes the CHD file from the /tmp directory when a game exists.  Below is an example of the ROM Zip layout of the Simpsons Bowling game using an embedded CHD file:

```
simpbowl.zip
   - 999a01.73
   - simpbowl.25c
   - zaxxon.u98
   - nvram
     - simpbowl.nv
   - chd
     - simpbowl.chd
```
