function Parent(name) {
  this.name = name;
}

Parent.prototype.getName = function () {
  console.log(this.name);
};

function Child(name) {
  this.sex = "boy";
  Parent.call(this, name);
}

Child.prototype = new Parent();

Child.prototype.getSex = function () {
  console.log(this.sex);
};

var child1 = new Child("child1");
var parent1 = new Parent("parent1");

function TinyNew(params) {
  return {};
}
