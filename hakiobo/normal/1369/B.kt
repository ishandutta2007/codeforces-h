import java.io.BufferedReader


fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t =br.readInt()
    repeat(t){
        val n = br.readInt()
        val s = br.readLine()
        var active = false
        var zeroFound = false
        var onesAtEnd = 0
        for(c in s){
            if(c == '0'){
                if(active){
                    zeroFound = true
                    onesAtEnd = 0
                } else {
                    sb.append(0)
                }
            } else {
                onesAtEnd++
                active = true
            }
        }
        if(zeroFound) sb.append(0)
        repeat(onesAtEnd){sb.append(1)}
        sb.append('\n')
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