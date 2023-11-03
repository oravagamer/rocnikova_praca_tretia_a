using Godot;

public partial class Paddle : Area2D {
    [Export] public int Speed { get; set; } = 400;
    [Export] public string GamePad { get; set; } = "0";
    
    private Vector2 _screenSize;
    private float _height;
    

    public override void _Ready() {
        _screenSize = GetViewportRect().Size;
        _height = GetNode<CollisionShape2D>("CollisionShape2D").Shape.GetRect().Size.Y;
    }

    public override void _Process(double delta) {
        var velocity = Vector2.Zero;

        if (Input.IsActionPressed("move_up_" + GamePad)) {
            velocity.Y -= 1;
        }

        if (Input.IsActionPressed("move_down_" + GamePad)) {
            velocity.Y += 1;
        }

        Position += velocity.Normalized() * Speed * (float)delta;
        Position = new Vector2(
            x: Position.X,
            y: Mathf.Clamp(Position.Y, 0 + _height / 2, _screenSize.Y - _height / 2));
    }
}