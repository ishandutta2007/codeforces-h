import java.io.BufferedReader
import kotlin.math.sign

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readInt()
    repeat(numCases) {
        var sum = 0L
        val n = br.readInt()
        var prev = 0
        repeat(n) {
            val num = br.readInt()
            if (prev.sign == num.sign) {
                prev = prev.coerceAtLeast(num)
            } else {
                sum += prev
                prev = num
            }
        }
        sb.append(sum + prev).append('\n')
    }
    print(sb)
}

private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val NL_INT = '\n'.toInt()

@Suppress("DuplicatedCode")
private fun BufferedReader.readInt(): Int {
    var ret = read()
    while (ret <= SPACE_INT) {
        ret = read()
    }
    val neg = ret == '-'.toInt()
    if (neg) {
        ret = read()
    }
    ret -= ZERO_INT
    var read = read()
    while (read >= ZERO_INT) {
        ret *= 10
        ret += read - ZERO_INT
        read = read()
    }

    while (read <= SPACE_INT && read != -1 && read != NL_INT) {
        mark(1)
        read = read()
    }
    if (read > SPACE_INT) {
        reset()
    }
    return if (neg) -ret else ret
}