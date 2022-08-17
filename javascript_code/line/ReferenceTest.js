

class Home {
    constructor(address) {
        this.address = address
    }

    toString() {
        return "Home{" +
            "address='" + this.address + '\'' +
            '}'
    }
}

class Person {
    constructor(name, age) {
        this.name = name
        this.age = age
        this.home = null
    }

    setHome(home) {
        this.home = home
    }

    toString() {
        return "Person{" +
            "name='" + this.name + '\'' +
            ", age=" + this.age +
            ", home=" + this.home.toString() +
            '}'
    }
}

const person = new Person("jeffy", 12)
person.setHome(new Home("杭州"))
console.log(person.toString())