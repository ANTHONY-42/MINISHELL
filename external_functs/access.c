void    test_access()
{
    //F_OK : Vérifie si le fichier existe.
    //R_OK : Vérifie si le fichier est lisible.
    //W_OK : Vérifie si le fichier est modifiable.
    //X_OK : Vérifie si le fichier est exécutable.
    if (access("./minishell", X_OK) == 0)
            ft_printf("Exists\n");
    else
            ft_printf("Do not exists\n");
}

int main()
{
	test_access();
	return (0);
}
