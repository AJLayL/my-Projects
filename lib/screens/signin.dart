import 'package:flutter/material.dart';
import 'package:dream_journal/widgets/alertdialog.dart';

class signIn extends StatefulWidget {
  const signIn({super.key});

  @override
  State<signIn> createState() => _signInState();
}

class _signInState extends State<signIn> {
  final TextEditingController loginIDcontroller = TextEditingController();
  final TextEditingController loginPasswordcontroller = TextEditingController();
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.blueAccent,
        titleTextStyle: TextStyle(fontSize: 35, fontWeight: FontWeight.bold),
        title: Text("Dream journal"),
      ),
      body: Center(
        child: Column(
          children: [
            Padding(padding: EdgeInsets.all(25)),
            Text(
              "Sign in",
              style: TextStyle(fontSize: 35, fontWeight: FontWeight.bold),
            ),
            Container(
              padding: EdgeInsets.all(8),
              child: TextField(
                controller: loginIDcontroller,
                decoration: const InputDecoration(
                  border: OutlineInputBorder(),
                  labelText: "Username",
                ),
              ),
            ),
            Container(
              padding: EdgeInsets.all(8),
              child: TextField(
                controller: loginPasswordcontroller,
                decoration: const InputDecoration(
                  border: OutlineInputBorder(),
                  labelText: "Password",
                ),
              ),
            ),
          ],
        ),
      ),
      floatingActionButton: FloatingActionButton.extended(
        onPressed: () {
          if (loginIDcontroller.text == 'admin' &&
              loginPasswordcontroller.text == '123') {
            Navigator.pushNamed(context, '/home');
          } else {
            showLoginErrorDialog(context);
          }
        },
        label: Text("sign in"),
        icon: Icon(Icons.login),
      ),
    );
  }
}
