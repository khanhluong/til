# Variable
> Java

```java
String name = "name";
final String name = "VALUE";
```
> Kotlin

```kotlin
var str : String?
str = null
```

# Check value NULL
```java
if(str != null){
  int strLen = str.length();
}
```

```kotlin
str?.let{
  val strLen = str.length
}
val strLen = str?.length
```

# String
> Todo

# Type casting check
> Java
```java
if(obj instanceOf Animal){
  obj.doSth();
}
Animal animal = (Animal) obj;
```

> Kotlin
```kotlin
if(obj is Animal){
}

var animal = object as Animal
var animal = objett as? Animal
```
# Switch case
> Java
```java
int number = 0;
switch(number){
  case 9:
  case 8:
    break;
   default:
   ...
}
```
> Kotlin
```kotlin
var number = 0;
var result = when(number){
  9, 10 -> "Value"
  in 1..3 -> "Value 1"
  else "NG"
}
````

# For Loop
> Java
```java
for (int i = 1; i <= 10 ; i++) { }

for (int i = 1; i < 10 ; i++) { }

for (int i = 10; i >= 0 ; i--) { }

for (int i = 1; i <= 10 ; i+=2) { }

for (int i = 10; i >= 0 ; i-=2) { }

for (String item : collection) { }

for (Map.Entry<String, String> entry: map.entrySet()) { }
```

> Kotlin
```kotlin
for (i in 1..10) { }

for (i in 1 until 10) { }

for (i in 10 downTo 0) { }

for (i in 1..10 step 2) { }

for (i in 10 downTo 0 step 2) { }

for (item in collection) { }

for ((key, value) in map) { }
```

# Collections
