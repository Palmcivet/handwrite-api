import { World } from "@jakeklassen/ecs";
import { Collision, Color, Position, Rectangle, Velocity } from "./components";
import { CollisionSystem, PhysicsSystem, RenderingSystem } from "./systems";

function getRandom(max: number, min = 0) {
  return Math.floor(Math.random() * max) + min;
}

let _world: World;

export function initWorld(canvas: HTMLCanvasElement) {
  const ctx = canvas.getContext("2d")!;

  _world = new World();

  for (let i = 0; i < 50; i++) {
    _world.addEntityComponents(
      _world.createEntity(),
      new Position(getRandom(canvas.width), getRandom(canvas.height)),
      new Velocity(getRandom(100, -50), getRandom(100, -50)),
      new Color(`rgb(${getRandom(255)}, ${getRandom(255)}, ${getRandom(255)})`),
      new Rectangle(getRandom(60, 10), getRandom(60, 10)),
      new Collision()
    );
  }

  _world.addSystem(new RenderingSystem(ctx));
  _world.addSystem(new CollisionSystem());
  _world.addSystem(new PhysicsSystem());
}

export function startWorld() {
  let dt = 0;
  let last = performance.now();

  function frame(hrt: DOMHighResTimeStamp) {
    dt = (hrt - last) / 1000;

    _world.updateSystems(dt);

    last = hrt;

    requestAnimationFrame(frame);
  }

  requestAnimationFrame(frame);
}
