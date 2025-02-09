# svenmod_starloader
An .asi file which loads SvenMod even without using its own launcher. (maybe unfinished)

# HOW TO BUILD
Just copy the repository onto your drive, open up `svenmod_starloader\svenmod_starloader.sln` file with MSVS 2015/2017/2019/2022 and hit Ctrl+Shift+B.

The artifact will be in `svenmod_starloader\Debug` or `svenmod_starloader\Release` folder.

Rename `svenmod_starloader.dll` into `svenmod_starloader.asi` and follow `HOW TO INSTALL`

# HOW TO INSTALL
Either follow `HOW TO BUILD` to build an artifact, or download one from Releases.

This plugin requires any .asi loader in order to be loaded, if you don't have any you can use mine -- https://github.com/autisoid/StarLoader

If you downloaded an artifact from Releases, just unpack the .zip file into your game ROOT folder (e.g. `C:\Program Files (x86)\Steam\steamapps\common\Sven Co-op\`) and launch the game, the plugin will be loaded, as well as SvenMod (you must have it too!)

Drop the `svenmod_starloader.asi` file into `starloader` folder located in your game ROOT folder (e.g. `C:\Program Files (x86)\Steam\steamapps\common\Sven Co-op\starloader`) and launch the game.

# SvenMod status
Since the OG repository for SvenMod (https://github.com/sw1ft747/svenmod) wasn't updated for Sven-5.26, my private (not anymore) update of SvenMod is available now at https://github.com/autisoid/svenmod.

Grab the `svemod.dll` file from either Releases, or build it on your own. Drop it as like you would install SvenMod normally, but launch the game with the original launcher in case you want it to be loaded by my loader.