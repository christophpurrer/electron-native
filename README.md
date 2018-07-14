# electron-native

This is a super simple Electron example, demonstrating how to package a native C component into an Electron app.
Based on: [https://github.com/electron/electron-quick-start](https://github.com/electron/electron-quick-start)

## To Use

To clone and run this repository you'll need [Git](https://git-scm.com), [Node.js](https://nodejs.org/en/download/) (which comes with [npm](http://npmjs.com)) and [yarn](https://yarnpkg.com/) installed on your computer. 

From your command line:

```bash
# Clone this repository
git clone https://github.com/christophpurrer/electron-native.git
# Go into the repository
cd electron-native
# Install dependencies
yarn install
# Run the app
yarn start
```
This will run the application.

## Package

The app integrates 2 Electron app packagers: [electron-builder](https://www.electron.build) and [electron-packager](https://github.com/electron-userland/electron-packager).

```bash
# Package via electron-build
yarn dist-via-electron-builder 
# Package via electron-packager
yarn dist-via-electron-packager
```

The crucial setting to packaging of native components work with electron-builder is:

```bash
  "build": {
    "files": [
      "**/*",
      "build/**/*"
    ]
  },
```
otherwise the native components are NOT included in the final package.

Contrary to [electron-packager](https://github.com/electron-userland/electron-packager) an [app.asar](https://electronjs.org/docs/tutorial/application-packaging) file is created by default by [electron-build](https://www.electron.build).

![app.asar](doc/app.asar.png "app.asar")

Disable it in the build block in package.json for further investigation in case things don't work as expected.

```bash
  "build": {
    "asar": false
  },
```

![app folder](doc/app.folder.png "app folder")

## Resources
The hello.cc sample is based on [Node.js C++ Addons](https://nodejs.org/api/addons.html) documentation.

## License

[CC0 1.0 (Public Domain)](LICENSE.md)
