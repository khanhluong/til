// An Iterable is a collection of elements that can be accessed sequentially.
Iterable iterableSample() {
  var iterable = ['Salad', 'Popcorn', 'Toast'];
  for (var element in iterable) {
    print(element);
  }
  return iterable;
}

void usingWhereInIterable() {
  var items = ['Salad', 'Popcorn', 'Toast', 'Lasagne'];

  var element1 = items.firstWhere((element) => element.length > 5);

  var element2 = items.where((element) => element.length > 5);

  var element3 = items.where((element) {
    return element.length > 5;
  });

  var element4 = items.firstWhere(
    (element) => element.length > 5,
    orElse: () => 'None!',
  );

  print('using firstWhere $element1');

  print('using where $element2');

  //Example: Using any() and every()

  // any(): Returns true if at least one element satisfies the condition.
  // every(): Returns true if all elements satisfy the condition.
  if (items.any((element) => element.contains('a'))) {
    print('At least one element contains "a"');
  }

  if (items.every((element) => element.length >= 5)) {
    print('All elements have length >= 5');
  }

  //fitering

  var evenNumbers = [1, -2, 3, 42].where((element) => element.isEven);

  print(evenNumbers);

  var numbersByTwo = [1, -2, 3, 42].map((e) => e * 3);

  print(numbersByTwo);
}

Iterable<EmailAddress> parseEmailAddresses(Iterable<String> strings) {
  return strings.map((email) => EmailAddress(email));
}

bool anyInvalidEmailAddress(Iterable<EmailAddress> emails) {
  return emails.any((email) => isValidEmailAddress(email));
}

Iterable<EmailAddress> validEmailAddresses(Iterable<EmailAddress> emails) {
  return emails.where((email) => isValidEmailAddress(email));
}

class EmailAddress {
  String address;

  EmailAddress(this.address);

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is EmailAddress &&
          runtimeType == other.runtimeType &&
          address == other.address;

  @override
  int get hashCode => address.hashCode;

  @override
  String toString() {
    return 'EmailAddress{address: $address}';
  }
}

bool isValidEmailAddress(var email) => RegExp(
        r"^[a-zA-Z0-9.a-zA-Z0-9.!#$%&'*+-/=?^_`{|}~]+@[a-zA-Z0-9]+\.[a-zA-Z]+")
    .hasMatch(email);
