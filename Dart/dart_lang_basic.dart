var name = 'Voyager I';

var year = 1977;

var fbybyObjects = ['Jupiter', 'Staturn', 'Uranus'];

enum Color { red, green, blue }

void main() {
  for (var i = 0; i < 4; i++) {
    print('hello $i');
    print('$name');
  }

  for (var obj in fbybyObjects) {
    print(obj);
  }

//   fibonacci(5);
  //fibonacci01(5);

  fbybyObjects.where((name) => name.contains('turn')).forEach(print);

  var voyager = Spacecraft('Voyager I', DateTime(1977, 9, 5));
  voyager.describe();

  var voyager3 = Spacecraft.unlaunched('Voyager III');
  voyager3.describe();

  var aColor = Color.blue;

  switch (aColor) {
    case Color.red:
      print('Red as roses');
      break;
    case Color.green:
      print('Green as grass');
      break;
    default:
      print(aColor);
      break;
  }

  //collection literals
  var name1 = <String>['Seth', 'Kathy', 'Lars'];
  var uniqueNames = <String>{'Seth', 'Kathy', 'Lars'};
  var pages = <String, String>{
    'index.html': 'Homepage',
  };

//   Generic collections and the types they contain
  var names = List<String>();
  names.addAll(['Seth', 'Kathy', 'Lars']);
  print(names is List<String>); // true
}

int fibonacci(int n) {
  if (n == 0 || n == 1) return n;
  var result = fibonacci(n - 1) + fibonacci(n - 2);
  return result;
}

int fibonacci01(int n) {
  var i, n, t1 = 0, t2 = 1, nextTerm;

  for (i = 1; i <= n; i++) {
    print(t1);
    nextTerm = t1 + t2;
    t1 = t2;
    t2 = nextTerm;
  }
  return 0;
}

class Spacecraft {
  String name;
  DateTime launchDate;

  Spacecraft(this.name, this.launchDate) {}

  Spacecraft.unlaunched(String name) : this(name, null);

  int get launchYear => launchDate?.year;

  void describe() {
    print('Spacecraft $name');
    if (launchDate != null) {
      var years = DateTime.now().difference(launchDate).inDays ~/ 365;
      print('Launched: $launchYear ($years years ago)');
    } else {
      print('Unlaunched');
    }
  }
}

class Orbiter extends Spacecraft {
  double altitude;
  Orbiter(String name, DateTime launchDate, this.altitude)
      : super(name, launchDate);
}

class Piloted {
  int astronauts = 1;
  void describeCrew() {
    print('Number of astronauts: $astronauts');
  }
}

class PilotCraft extends Spacecraft with Piloted {
  PilotCraft(String name, DateTime launchDate) : super(name, launchDate);
}

//generic
abstract class Cache<T> {
  T getByKey(String key);
  void setByKey(String key, T value);

  //generic method
  T first<T>(List<T> ts) {
    T tmp = ts[0];
    return tmp;
  }
}

//handing future
