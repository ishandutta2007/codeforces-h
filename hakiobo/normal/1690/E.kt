import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val k = br.readInt()
        var ans = 0L
        val nums = MutableList<Int>(n) {
            val num = br.readInt()
            ans += num.toLong() / k
            num % k
        }
        nums.sort()
        var i = 0
        var j = n - 1
        while (i < j) {
            if(nums[i] + nums[j] >= k) {
                ans++
                i++
                j--
            } else {
                i++
            }
        }
        bw.appendLine("$ans")
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