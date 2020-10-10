# Kotlin learing tutorial


`Kotlin` Advance

* Full support for `Lambda` expressions.
* `Data Class`
* `Null safety`

## Variable
```kotlin
    var name: String = "ken"
    var age: Int = 18
```

The spectific type can be written literally.
```kotlin
    var name = "ken"
    var age = 18
```

*In Kotlin, everything is an Object. Not like Java, there is no primitive basic type.*

They have Integer, Float or Boolean but thay all exist as an Object.

## Constants

Simply using val for constants
```kotlin
const val NAME: String = "ken"
```

What is the difference between that lateinitand by lazy?

* by lazy{}Can only be used in valtypes and lateinitonly in vartypes
* lateinitCannot be used on nullable attributes and javabasic types, otherwise lateinitan error will be reported

## Class

### Constructor

## Interface


## Function


## `Lambda` expression`

A class with few parameters can be written in one line

```kotlin
    class Person(id: Int, name: String)
```


If you using inheritance:

```kotlin
class Person(
    id: Int, 
    name: String,
    surname: String
) : Human(id, name) {
    // ……
}
```

## Unit
If the funtion return `Unit`, the return type should be omitted

```kotlin
fun foo(){

}

fun foo(): Unit {

}
```


## Kotlin following build type

```
Type    Bit width
Double  64
Long    64
Float   32
Int     32
Short   16
Byte    8
```

## Reference equality

Reference equality is judged by the operation of ===its negative form !===. Evaluate a === bif and only if aand bpoint to the same object true.






Ref from https://github.com/CharonChui/