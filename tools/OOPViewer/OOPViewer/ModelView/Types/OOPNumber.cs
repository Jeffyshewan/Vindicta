﻿namespace OOPViewer.ModelView.Types
{
    public class OOPNumber : OOPVariable
    {
        public double Value { get; set; } = 0;
        public override string ToString() { return Value.ToString(); }
        public override string GetTypeName() { return "Number"; }
    }
}
