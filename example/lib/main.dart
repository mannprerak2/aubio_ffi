import 'dart:ffi';

import 'package:aubio_ffi/aubio_bindings.dart';
import 'package:flutter/material.dart';

import 'package:aubio_ffi/aubio_ffi.dart' as aubio_ffi;

void main() {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({super.key});

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  late DynamicLibrary aubioDll;
  late AubioBindings aubioBindings;

  @override
  void initState() {
    aubioDll = aubio_ffi.openAubioDynamicLibrary();
    aubioBindings = aubio_ffi.initAubioBindings(dynamicLibrary: aubioDll);
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    const textStyle = TextStyle(fontSize: 25);
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Native Packages'),
        ),
        body: SingleChildScrollView(
          child: Container(
            padding: const EdgeInsets.all(10),
            child: Column(
              children: [
                Text(
                  'Provides new_fvec: ${aubioDll.providesSymbol("new_fvec")}',
                  style: textStyle,
                  textAlign: TextAlign.center,
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }
}
