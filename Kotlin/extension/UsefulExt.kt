fun Int.toDate(): Date = Date(this.toLong() * 1000L)

val Int.asDate: Date
    get() = Date(this.toLong() * 1000L)


fun String.toDate(format: String): Date? {
    val dateFormatter = SimpleDateFormat(format, Locale.getDefault())
    return try {
        dateFormatter.parse(this)
    } catch (e: ParseException) {
        return null
    }
}

fun Date.toString(format: String): String {
    val dateFormatter = SimpleDateFormat(format, Locale.getDefault())
    return dateFormatter.format(this)
}

fun Int.centToDollars(): Double = this.toDouble() / 100.0

fun Int.centToDollarsWithFormat(currency: String): String {
    val dollars = this.toDouble() / 100.0
    val cents = this.toDouble() % 100.0
    return String.format("%s %d.%02d", currency, dollars, cents)

}

fun Double.toPrice(): String {
    val pattern = "#,###.00"
    val decimalFormat = DecimalFormat(pattern)
    decimalFormat.groupingSize = 3

    return "€" + decimalFormat.format(this)
}

val String.containsDigit: Boolean
    get() = matches(Regex(".*[0-9].*"))

val String.isAlphanumeric: Boolean
    get() = matches(Regex("[a-zA-z0-9]*"))

val String.asUri: Uri?
    get() = try {
        if (URLUtil.isValidUrl(this)) {
            Uri.parse(this)
        } else
            null
    } catch (e: Exception) {
        null
    }

val Context.versionName: String?
    get() = try {
        null
    } catch (e: Exception) {
        null
    }

val Any.deviceName: String
    get() = {
        val manufacturer = Build.MANUFACTURER
        val model = Build.MODEL
        if (model.startsWith(manufacturer))
            model.capitalize(Locale.getDefault())
        else
            manufacturer.capitalize(Locale.getDefault()) + " " + model
    }.toString()