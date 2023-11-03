using Godot;

public partial class Paddle : Area2D {
    [Export] public int Speed { get; set; } = 400;
    public Vector2 ScreenSize;

    public override void _Ready() {
        ScreenSize = GetViewportRect().Size;
    }

    public override void _Process(double delta) {
        var velocity = Vector2.Zero;
    }
}