import 'package:flutter/material.dart';

Future<void> showLoginErrorDialog(BuildContext context) async {
  return showDialog(
    context: context,
    barrierDismissible: true,
    builder: (BuildContext context) {
      return AlertDialog(
        title: const Text("Log in Error"),
        content: const SingleChildScrollView(
          child: ListBody(
            children: <Widget>[Text("Username or Password is wrong!")],
          ),
        ),
        actions: <Widget>[
          TextButton(
            child: const Text("Close"),
            onPressed: () {
              Navigator.of(context).pop();
            },
          ),
        ],
      );
    },
  );
}
