AirBnB clone - The console

## project introduction 

it's a team project to practice some real world projects cloning **AirBnB**

The console is a command interpreter to manage objects abstraction between objects and how they are stored.

The console willl perform the following tasks:

* create a new object
* retrive an object from a file
* do operations on objects
* destroy an object

## 0x03 Installation

```bash
git clone https://github.com/ddedo2468/AirBnB_clone.git
```

change to the `AirBnb` directory and run the command:

```bash
 ./console.py
```

## 0x05 Usage

* Start the console in interactive mode:

```bash
$ ./console.py
(hbnb)
```

```bash
(hbnb) help

Documented commands (type help <topic>):
========================================
EOF  all  count  create  destroy  help  quit  show  update

(hbnb)
```

* Quit the console:

```bash
(hbnb) quit
$
```

* Create

> *Creates a new instance of a given class. The class' ID is printed and the instance is saved to the file file.json.*

```bash
(hbnb) create BaseModel
95424ce2-5d87-4ac8-9411-2faccba4886c
(hbnb)
```


* Show

> *shows all information about a class

```bash
(hbnb) show BaseModel 95424ce2-5d87-4ac8-9411-2faccba4886c
[BaseModel] (95424ce2-5d87-4ac8-9411-2faccba4886c) {'id': '95424ce2-5d87-4ac8-9411-2faccba4886c', 'created_at': datetime.datetime(2023, 11, 11, 12, 20, 33, 606557),
'updated_at': datetime.datetime(2023, 11, 11, 12, 20, 33, 606580)}
```

* Destroy

> *Deletes an instance of a given class with a given ID.*
> *Update the file.json

```bash
(hbnb) destroy BaseModel 49844967-f7ab-42dd-af0f-22cb1291a854
(hbnb) 
```


* update

> *Updates an instance based on the class name, id, and kwargs passed.*
> *Update the file.json*

```bash
(hbnb) update BaseModel 95424ce2-5d87-4ac8-9411-2faccba4886c full_name "John Doe"

(hbnb) show BaseModel 95424ce2-5d87-4ac8-9411-2faccba4886c

[BaseModel] (95424ce2-5d87-4ac8-9411-2faccba4886c) {'id': '95424ce2-5d87-4ac8-9411-2faccba4886c', 'created_at': datetime.datetime(2023, 11, 11, 12, 20, 33, 606557),
'updated_at': datetime.datetime(2023, 11, 11, 12, 24, 18, 831089), 'full_name': '"John'}
```


* all

> *Prints all string representation of all instances of a given class.*
> *If no class is passed, all classes are printed.*

```bash
['[BaseModel] (123) {\'id\': \'123\', \'created_at\': datetime.datetime(2023, 11, 9, 17, 34, 40, 49629), \'updated_at\': datetime.datetime(2023, 11, 9, 12, 9, 28, 385875), \'first_name\': \'"Betty"\'}', "[BaseModel] (545d69a8-bbf3-433d-9f35-14fd03d8ed6a) {'id': '545d69a8-bbf3-433d-9f35-14fd03d8ed6a',
'created_at': datetime.datetime(2023, 11, 9, 17, 37, 59, 793602), 'updated_at': datetime.datetime(2023, 11, 9, 17, 37, 59, 793602)}", "[BaseModel] (49844967-f7ab-42dd-af0f-22cb1291a854)
{'id': '49844967-f7ab-42dd-af0f-22cb1291a854', 'created_at': datetime.datetime(2023, 11, 9, 17, 39, 27, 37377), 'updated_at': datetime.datetime(2023, 11, 9, 17, 39, 27, 37377)}"
```


## Credits

> *Console team: [Sayed](https://github.com/sayedH-Dev) & [Abdullah](https://github.com/ddedo2468)*

