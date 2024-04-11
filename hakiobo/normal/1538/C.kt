import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val l = br.readInt()
        val r = br.readInt()
        val nums = List(n) { br.readInt() }.sorted()
        var ans = 0L
        for (i in 0 until n) {
            var high = n
            var low = i + 1
            var mid1 = (high + low) shr 1
            while (low != high) {
                if (nums[mid1] + nums[i] > r) {
                    high = mid1
                } else {
                    low = mid1 + 1
                }
                mid1 = (high + low) shr 1
            }

            high = n
            low = i + 1
            var mid2 = (high + low) shr 1
            while (low != high) {
                if (nums[mid2] + nums[i] >= l) {
                    high = mid2
                } else {
                    low = mid2 + 1
                }
                mid2 = (high + low) shr 1
            }
            ans += mid1 - mid2
        }
        sb.appendLine(ans)
    }
    print(sb)
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