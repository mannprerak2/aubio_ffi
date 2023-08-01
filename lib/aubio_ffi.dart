import 'dart:ffi';
import 'dart:io';

import 'package:aubio_ffi/aubio_bindings.dart';

const String _libName = 'aubio_ffi';

DynamicLibrary openAubioDynamicLibrary() {
  if (Platform.isMacOS || Platform.isIOS) {
    return DynamicLibrary.open('$_libName.framework/$_libName');
  }
  if (Platform.isAndroid || Platform.isLinux) {
    return DynamicLibrary.open('lib$_libName.so');
  }
  if (Platform.isWindows) {
    return DynamicLibrary.open('$_libName.dll');
  }
  throw UnsupportedError('Unknown platform: ${Platform.operatingSystem}');
}

/// Initialies a new AubioBindings object.
AubioBindings initAubioBindings({DynamicLibrary? dynamicLibrary}) {
  dynamicLibrary ??= openAubioDynamicLibrary();
  return AubioBindings(dynamicLibrary);
}
