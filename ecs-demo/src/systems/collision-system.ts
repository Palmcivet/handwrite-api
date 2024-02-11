import { System, World } from "@jakeklassen/ecs";
import { Position, Rectangle, Velocity, Collision } from "../components";

export class CollisionSystem extends System {
  public update(world: World): void {
    for (const [entityA, componentsA] of world.view(
      Position,
      Rectangle,
      Velocity
    )) {
      for (const [entityB, componentsB] of world.view(
        Position,
        Rectangle,
        Collision
      )) {
        if (entityA === entityB) {
          continue;
        }

        const positionA = componentsA.get(Position);
        const velocityA = componentsA.get(Velocity);
        const rectangleA = componentsA.get(Rectangle);

        const positionB = componentsB.get(Position);
        const rectangleB = componentsB.get(Rectangle);

        if (
          positionA.x < positionB.x + rectangleB.width &&
          positionA.x + rectangleA.width > positionB.x &&
          positionA.y < positionB.y + rectangleB.height &&
          positionA.y + rectangleA.height > positionB.y
        ) {
          positionA.x -= velocityA.x;
          positionA.y -= velocityA.y;
        }
      }
    }
  }
}
