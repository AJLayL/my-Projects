import 'package:flutter/material.dart';

class home extends StatefulWidget {
  const home({super.key});

  @override
  State<home> createState() => _homeState();
}

class _homeState extends State<home> {
  List JournalTitle = ["test 1", "test 2"];
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        titleTextStyle: TextStyle(fontSize: 35, fontWeight: FontWeight.bold),
        title: Text("Dream Journal"),
        backgroundColor: Colors.blueAccent,
      ),
      body: Center(
        child: Container(
          padding: EdgeInsets.all(8),
          child: ListView.builder(
            itemCount: JournalTitle.length,
            itemBuilder: (context, index) {
              return Container(
                margin: EdgeInsets.all(8),
                decoration: BoxDecoration(
                  color: Colors.blueAccent[200],
                  borderRadius: BorderRadius.circular(12),
                ),
                child: ListTile(
                  title: Text(JournalTitle[index]),
                  onTap: () {
                    Navigator.pushNamed(context, '/content');
                  },
                ),
              );
            },
          ),
        ),
      ),
    );
  }
}
