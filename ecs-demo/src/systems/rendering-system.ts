import { System, World } from "@jakeklassen/ecs";
import { Color, Position, Rectangle } from "../components";

export class RenderingSystem extends System {
  constructor(private readonly context: CanvasRenderingContext2D) {
    super();
  }

  public update(world: World, _dt: number): void {
    this.context.clearRect(
      0,
      0,
      this.context.canvas.width,
      this.context.canvas.height
    );

    for (const [, componentMap] of world.view(Position, Rectangle, Color)) {
      const position = componentMap.get(Position)!;
      const rectangle = componentMap.get(Rectangle)!;
      const color = componentMap.get(Color)!;

      this.context.fillStyle = color.color;
      this.context.fillRect(
        position.x,
        position.y,
        rectangle.width,
        rectangle.height
      );
    }
  }
}
