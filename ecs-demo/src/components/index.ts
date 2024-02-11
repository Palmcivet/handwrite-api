import { Component } from "@jakeklassen/ecs";

export class Position extends Component {
  constructor(public x: number, public y: number) {
    super();
  }
}

export class Rectangle extends Component {
  constructor(public readonly width: number, public readonly height: number) {
    super();
  }
}

export class Color extends Component {
  constructor(public color: string) {
    super();
  }
}

export class Velocity extends Component {
  constructor(public x = 0, public y = 0) {
    super();
  }
}

export class Collision extends Component {
  constructor() {
    super();
  }
}
