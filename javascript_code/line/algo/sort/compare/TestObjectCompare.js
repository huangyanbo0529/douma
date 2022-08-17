

class Person {
    constructor(name, age) {
        this.name = name
        this.age = age
    }

    toString() {
        return "Person{" +
            "name='" + this.name + '\'' +
            ", age=" + this.age +
            '}'
    }
}


const p1 = new Person("douma", 40)
const p2 = new Person("laotang", 30)
const p3 = new Person("douma1", 32)
const p4 = new Person("laotang2", 33)

const people = [p1, p2, p3, p4]

// js 内置排序
// 按照人的年龄排序
people.sort((p1, p2) => p1.age - p2.age)

for (const person of people) {
    console.log(person.toString())
}