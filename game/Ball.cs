using Godot;

public partial class Ball : RigidBody2D {
    [Signal]
    public delegate void OutOfBoundsEventHandler();
    
    [Export] public float Speed { get; set; } = 400;
    
    private Vector2 _screenSize;
    private Vector2 _size;
    private Vector2 _velocity;
    
    public override void _Ready() {
        var random = new RandomNumberGenerator();
        random.Randomize();
        _screenSize = GetViewportRect().Size;
        _size = GetNode<CollisionShape2D>("CollisionShape2D").Shape.GetRect().Size;
        _velocity = new Vector2(
            x: random.RandfRange(-1f, 1f),
            y: random.RandfRange(-1f, 1f)
        );
    }

    public override void _Process(double delta) {
        if (Position.X - _size.X / 2 < 100 || Position.X + _size.X / 2 < _screenSize.X - 100) {
            EmitSignal(SignalName.OutOfBounds);
        }

        if (Position.Y - _size.Y / 2 < 0 || Position.Y + _size.Y / 2 > _screenSize.Y) {
            _velocity.Y = -_velocity.Y;
        }

        Position += _velocity * Speed * (float)delta;
        
    }
}