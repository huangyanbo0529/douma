

class IpLocation {
    constructor(startIp, endIp, locationCity) {
        this.startIp = startIp
        this.endIp = endIp
        this.locationCity = locationCity
    }
}

class IpLocationParser {

    // ip 数据从外面传进来
    constructor(lines) {
        this.sortedIpLocations = []

        // 1. 解析 ip 地址段
        for (const line of lines) {
            const temps = line.split(" ")
            const ipLocation = new IpLocation(this.ip2Score(temps[0]), this.ip2Score(temps[1]), temps[2])
            this.sortedIpLocations.push(ipLocation)
        }

        // 2. 按照起始 ip 进行升序排列
        // 时间复杂度：O(nlogn)
        this.sortedIpLocations.sort((o1, o2) => {
            return o1.startIp - o2.startIp
        })
    }

    ip2Score(ip) {
        const temps = ip.split(".")
        const score = 256 * 256 * 256 * parseInt(temps[0])
            + 256 * 256 * parseInt(temps[1])
            + 256 * parseInt(temps[2])
            + parseInt(temps[3]);
        return score
    }

    // 二分查找指定 ip 对应的城市
    // 时间复杂度：O(logn)
    getIpLocation(ip) {
        const score = this.ip2Score(ip)
        let left = 0
        let right = this.sortedIpLocations.length - 1
        while (left <= right) {
            const mid = left + Math.floor((right - left) / 2)
            if (score >= this.sortedIpLocations[mid].startIp) {
                if (mid == this.sortedIpLocations.length - 1
                    || this.sortedIpLocations[mid + 1].startIp > score) {
                    if (score <= this.sortedIpLocations[mid].endIp) {
                        return this.sortedIpLocations[mid].locationCity
                    } else {
                        // bug 修复：
                        // 如果查询的 ip > (mid 对应 ip 段的 startIp) 且 ip < (mid + 1 对应 ip 段的 startIp)，
                        // 但是如果 ip > (mid 对应 ip 段的 endIp)
                        // 说明 ip 超出了 mid 对应的 ip 段，又不属于 mid + 1 对应 ip 段直接退出即可
                        break
                    }
                } else {
                    left = mid + 1
                }
            } else { // target < nums[mid]
                right = mid - 1
            }
        }
        return null;
    }
}

const lines = [
    "202.102.134.0 202.102.134.255 江西南昌市",
    "202.102.135.0 202.102.136.255 江西九江市",
    "202.102.156.34 202.102.157.255 江西景德镇",
    "202.101.48.0 202.101.48.255 浙江杭州市",
    "202.101.49.15 202.101.51.251 浙江温州市",
    "202.102.56.0 202.102.56.255 江西上饶市"
]

const ipLocationParser = new IpLocationParser(lines)
console.log(ipLocationParser.getIpLocation("202.101.48.198"))