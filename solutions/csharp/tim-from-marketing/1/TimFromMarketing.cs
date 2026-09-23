static class Badge
{
    public static string Print(int? id, string name, string? department)
    {
            if(department == null)
                department = "OWNER";

            department = department.ToUpper();
        
            if(id != null)
                return $"[{id}] - {name} - {department}";
            else
                return $"{name} - {department}";
    }
}
