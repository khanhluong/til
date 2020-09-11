import org.junit.Assert
import org.junit.Test

/**
 * ref: https://blog.kotlin-academy.com/mastering-kotlin-scoped-and-higher-order-functions-23e2dd34d660
 */
class HigherOrderFunction {

    @Test
    @Throws(Exception::class)
    fun addition_isCorrect() {
        Assert.assertEquals(4, 2 + 2.toLong())

        doSomething { randomFunction() }

        doSomething {
            dynamic
        }

        doSomething4<Int> {
            100
        }
        doSomeThing5<String, Int>("Hello") {
            this.substring(1)
            "from Inside"
            1
        }

        "khanh".callMyAnonymousLambda { name -> println("My name is $name") }

        "khanh".myLet {
            println("My name is $it")
        }
    }


    fun randomFunction() {
        println("I am random function")
    }

    fun doSomething(block: () -> Unit) {
        block()
    }

    fun doSomething1(xyz: () -> Unit) { // valid, xyz is the param name
    }

    fun doSomething2(block: () -> String) {
        val someString = block()
    }

    //Call the passed function with parameters
    interface CustomFunctionType : () -> Unit {
        override fun invoke() {

        }
    }

    private val dynamic = object : CustomFunctionType {
        override fun invoke() {
            super.invoke()
            print("hello")
        }
    }

    fun doSomething3(block: String.() -> Unit) {
        "Sample".block()
    }

    fun <R> doSomething4(block: String.(int: Int) -> R) {
        println("Gaurav".block(1))
    }

    fun <T, R> doSomeThing5(t: T, block: T.() -> R) {
        print(t.block())
    }

    fun <T, R> T.doSomeThing(block: T.() -> R) {
        println(block())
    }

    fun <T> T.callMyAnonymousLambda(block: (T) -> Unit) {
        block(this)
    }

    fun <T, R> T.myLet(block: (T) -> R): R {
        return block(this)
    }
}