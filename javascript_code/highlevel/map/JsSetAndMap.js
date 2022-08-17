// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


/*************** Js 中的 Set *********************/
const set = new Set()
// 往 set 中添加数据
set.add(1)
set.add(3)
set.add(1)
set.add(2)
console.log(set) // Set { 1, 3, 2 } --》 Set 会维护插入的顺序

// 判断 set 中是否存在某个值
if (set.has(1)) {
    console.log("set contains 1")
}

// 删除 set 中指定的数据
set.delete(1)
console.log(set) // Set { 3, 2 }

// 遍历 set
for (const ele of set) {
    console.log(ele)
}

/*************** Js 中的 Map *********************/
const map = new Map()
// 往 map 中添加 key-value 键值对
map.set(1, 2)
map.set(2, 3)
map.set(2, 8)
map.set(4, 3)
console.log(map) // Map { 1 => 2, 2 => 8, 4 => 3 }

// 根据 key 拿到 value
console.log(map.get(2))

// 判断 Map 中是否存在某个 key
if (map.has(3)) {
    console.log("Map 中存在键 = 3")
}


// 删除 map 中指定的 key
map.delete(2)
console.log(map) // Map { 1 => 2, 4 => 3 }

// 遍历 map 方法一
for (const item of map) {
    console.log(`${item[0]} -> ${item[1]}`)
}

// 遍历 map 方法二: 遍历所有的 key
for (const key of map.keys()) {
    console.log(`${key} -> ${map.get(key)}`)
}

// 遍历 map 方法三: 遍历所有的 value
for (const value of map.values()) {
    console.log(value)
}

// 遍历 map 方法四
for (const item of map.entries()) {
    console.log(`${item[0]} -> ${item[1]}`)
}
