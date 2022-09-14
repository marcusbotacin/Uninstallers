# Uninstallers

Additional material for the paper analyzing uninstaller applications.

## Organization

## Enumerating MSI (Un)Installers
  * This method is not much used by uninstallers, but you might want to try it.
  * Available in the *MSIEnum* directory.

## Killing Uninstaller process
  * Available in the *Killer* directory.

## Emptying process list via userland hooking
  * You can hook key functions using [A DLL hooking solution](https://github.com/marcusbotacin/In.Memory/tree/master/Interception/Windows)
  * You can load the hooking DLL using a [Loader](https://github.com/marcusbotacin/MalwareFuzz/tree/main/Windows/Loader)

## Emptying process list via kerneland interposition
  * You can intercept accessed files/keys using [a kernel filter](https://github.com/marcusbotacin/Malware.Multicore/blob/master/Test.Thread.Capture/Test.Thread.Capture/Test.Thread.Capture.c)
