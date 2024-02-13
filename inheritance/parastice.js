function Parent(name) {
  this.name = name;
  this.face = "cry";
  this.color = ["white", "red"];
}

Parent.prototype.feature = ["cute"];
Parent.prototype.getFeature = function () {
  console.log(this.feature);
};

function Child(name) {
  Parent.call(this, name);
  this.sex = "boy";
  this.face = "smile";
}

Child.prototype = Object.create(Parent.prototype);
Child.prototype.contructor = Child;

var child1 = new Child("child1");
child1.color.push("yellow");
var child2 = new Child("child2");
child2.feature = ["sun"];

child1.getFeature();
child2.getFeature();
