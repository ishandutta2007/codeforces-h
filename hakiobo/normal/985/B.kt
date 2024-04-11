import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val m = br.readInt()
    val grid = Array(n) {
        br.readLine()
    }
    val lampCount = IntArray(m)
    for (switch in 0 until n) {
        for (lamp in 0 until m) {
            if (grid[switch][lamp] == '1') {
                lampCount[lamp]++
            }
        }
    }
    var good = false
    for(switch in 0 until n){
        var essential = false
        for(lamp in 0 until m){
            if(grid[switch][lamp] == '1' && lampCount[lamp] == 1){
                essential = true
            }
        }
        if(!essential) good = true
    }
    if(good) print("YES") else print("NO")
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