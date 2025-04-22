import 'package:flutter/material.dart';

class contents extends StatelessWidget {
  const contents({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text("Dream Journal")),
      body: Center(child: Column(children: [Text("hello!")])),
    );
  }
}
