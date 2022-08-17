class IpLocation:
    def __init__(self, start_ip, end_ip, location_city):
        self.start_ip = start_ip
        self.end_ip = end_ip
        self.location_city = location_city


class IpLocationParser:
    def __init__(self):
        self.sorted_ip_locations = []
        # 1. 读取文件，解析 ip 地址段
        with open("C:/workspace/douma-algo/data/ip_location.txt", 'r', encoding="utf-8") as reader:
            lines = reader.readlines()
        for line in lines:
            temps = line.split(" ")
            ip_location = IpLocation(self.ip2Score(temps[0]), self.ip2Score(temps[1]), temps[2])
            self.sorted_ip_locations.append(ip_location)

        # 2. 按照起始 ip 进行升序排列
        # 时间复杂度：O(nlogn)
        self.sorted_ip_locations.sort(key=lambda x: x.start_ip)

    # 将ip转成长整型
    def ip2Score(self, ip):
        temps = ip.split(".")
        score = 256 * 256 * 256 * int(temps[0]) \
                + 256 * 256 * int(temps[1]) \
                + 256 * int(temps[2]) \
                + int(temps[3])
        return score

    # 二分查找指定 ip 对应的城市
    # 时间复杂度：O(logn)
    def getIpLocation(self, ip):
        score = self.ip2Score(ip)
        # 在 sortedIpLocations 中找到最后一个 startIp 小于等于 score 的这个 ip 段
        left, right = 0, len(self.sorted_ip_locations) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if score >= self.sorted_ip_locations[mid].start_ip:
                if mid == len(self.sorted_ip_locations) - 1 or self.sorted_ip_locations[mid + 1].start_ip > score:
                    if score <= self.sorted_ip_locations[mid].end_ip:
                        return self.sorted_ip_locations[mid].location_city
                    else:
                        # bug 修复：
                        # 如果查询的 ip > (mid 对应 ip 段的 startIp) 且 ip < (mid + 1 对应 ip 段的 startIp)，
                        # 但是如果 ip > (mid 对应 ip 段的 endIp)
                        # 说明 ip 超出了 mid 对应的 ip 段，又不属于 mid + 1 对应 ip 段直接退出即可
                        break
                else:
                    left = mid + 1
            else:
                right = mid - 1
        return None


if __name__ == '__main__':
    te = IpLocationParser()
    print(te.getIpLocation("202.101.48.198"))
