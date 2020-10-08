# KotlinCheatSheet

## When Expression

when (x) {
    1 -> print("x == 1")
    2 -> print("x == 2")
    else -> { // Note the block
        print("x is neither 1 nor 2")
    }
}

## Generic (https://kotlinlang.org/docs/reference/generics.html)