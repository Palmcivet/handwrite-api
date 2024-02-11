import { System, World } from "@jakeklassen/ecs";
import { Position, Velocity, Rectangle } from "../components";

export class PhysicsSystem extends System {
  constructor() {
    super();
  }

  public update(world: World, dt: number): void {
    for (const [, componentMap] of world.view(Position, Velocity, Rectangle)) {
      const position = componentMap.get(Position);
      const velocity = componentMap.get(Velocity);

      position.x += velocity.x * dt;
      position.y += velocity.y * dt;
    }
  }
}
