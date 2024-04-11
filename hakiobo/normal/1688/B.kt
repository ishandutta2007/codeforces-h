import java.io.BufferedReader
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        var extraMoves = Integer.numberOfTrailingZeros(br.readInt())
        var numOdd = if (extraMoves == 0) 1 else 0
        repeat(n - 1) {
            val num = br.readInt()
            if (num and 1 == 1) numOdd++
            extraMoves = min(extraMoves, Integer.numberOfTrailingZeros(num))
        }
        val ans = if (numOdd == 0) {
            n - 1 + extraMoves
        } else {
            n - numOdd
        }
        bw.appendLine(ans.toString())
    }
    bw.flush()
}

private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val NL_INT = '\n'.toInt()

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