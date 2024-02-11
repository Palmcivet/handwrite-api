import { initWorld, startWorld } from "./world";

const canvas = document.createElement("canvas");

canvas.style.border = "2px solid black";
canvas.width = 1024;
canvas.height = 768;

document.querySelector<HTMLDivElement>("#app")?.appendChild(canvas);

initWorld(canvas);
startWorld();
