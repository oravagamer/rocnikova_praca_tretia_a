using Godot;

public partial class Paddle0 : Area2D {
    [Export] public int Speed { get; set; } = 400;
    public Vector2 ScreenSize;

    public override void _Ready() {
        ScreenSize = GetViewportRect().Size;
    }

    public override void _Process(double delta) {
        var velocity = Vector2.Zero;

        if (Input.IsActionPressed("move_up_0")) {
            velocity.X -= 1;
        }

        if (Input.IsActionPressed("move_down_0")) {
            velocity.X += 1;
        }

        Position += velocity.Normalized() * Speed * (float)delta;
        Position = new Vector2(
            x: Mathf.Clamp(Position.X, 0, ScreenSize.X),
            y: Position.Y);
    }
}