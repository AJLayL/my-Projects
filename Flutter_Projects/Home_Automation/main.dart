import 'package:flutter/material.dart';

void main() {
  runApp(const myApp());
}

class myApp extends StatelessWidget {
  const myApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Homestay Automation',
      theme: ThemeData(primarySwatch: Colors.cyan),
      home: mainPage(),
    );
  }
}

class mainPage extends StatelessWidget {
  final List<String> devices = [
    'esp32.device1',
    'esp32.device2',
    'esp32.device3',
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Homestay Automation Admin'),
        backgroundColor: Colors.cyan,
      ),
      body: Container(
        color: const Color.fromARGB(255, 235, 235, 235),
        child: ListView.builder(
          itemCount: devices.length,
          itemBuilder: (context, index) {
            return ListTile(
              title: Text(devices[index]),
              trailing: Icon(Icons.arrow_forward),
              onTap: () {
                Navigator.push(
                  context,
                  MaterialPageRoute(
                    builder:
                        (context) =>
                            deviceStatusScreen(deviceName: devices[index]),
                  ),
                );
              },
            );
          },
        ),
      ),
    );
  }
}

class deviceStatusScreen extends StatelessWidget {
  final String deviceName;

  deviceStatusScreen({required this.deviceName});

  void _resetDevice(BuildContext context) {
    showDialog(
      context: context,
      builder: (context) {
        return AlertDialog(
          title: Text('reset'),
          content: Text('reset is done!'),
          actions: [
            TextButton(
              onPressed: () => Navigator.pop(context),
              child: Text('OK!'),
            ),
          ],
        );
      },
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text(deviceName), backgroundColor: Colors.cyan),
      body: Container(
        color: Colors.grey,
        child: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Text('Status: Connected!', style: TextStyle(fontSize: 20)),
              SizedBox(height: 20),
              ElevatedButton(
                onPressed: () => _resetDevice(context),
                child: Text('reset'),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
