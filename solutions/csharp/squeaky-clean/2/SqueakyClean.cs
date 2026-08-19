using System.Text;

public static class Identifier
{
    public static string Clean(string identifier)
    {
        var result = new StringBuilder();
        
        for (int i = 0; i < identifier.Length; i++)
        {
            char c = identifier[i];

            switch (c)
            {
                case ' ':
                    result.Append('_');
                    break;

                case '-' when i + 1 < identifier.Length:
                    result.Append(char.ToUpperInvariant(identifier[++i]));
                    break;

                case >= 'α' and <= 'ω':
                    break;

                case var _ when char.IsControl(c):
                    result.Append("CTRL");
                    break;

                case var _ when char.IsLetter(c):
                    result.Append(c);
                    break;
            }
        }
        return result.ToString();
    }
}
