import 'package:flutter/material.dart';
import 'signin.dart';
import 'home.dart';
import 'content.dart';

//open sign in page
//read

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: "Dream Journal",
      theme: ThemeData(primaryColor: Colors.deepPurple),
      initialRoute: "/",
      routes: {
        '/': (context) => signIn(),
        '/home': (context) => home(),
        '/content': (context) => contents(),
      },
    );
  }
}
