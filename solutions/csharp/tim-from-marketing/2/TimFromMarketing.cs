static class Badge
{
    public static string Print(int? id, string name, string? department)
    {
            department = (department ?? "OWNER").ToUpper();

            return (id != null) ? $"[{id}] - {name} - {department}" : $"{name} - {department}";
    }
}
