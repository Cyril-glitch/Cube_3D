#include "../inc/cube_3d.h"
void    ft_parse_assets(t_data *data, t_map *map, char *file_path)
{
    (void)map;
    int fd;
    char *line;
    int is_valid_line;

    fd = ft_open_file(data, file_path);
    is_valid_line = 1;
    while (is_valid_line)
    {
        line = ft_get_next_line(fd);
        if (line == NULL)
            break ;
        if (ft_isspace_line(line))
            continue ;
        else if (ft_is_tex_line(data, line))
            printf("%s\n", line);
            //ft_load_texture(data, line);  
        else if (ft_is_color_line(data, line))
            printf("%s\n", line);
            //ft_load_colors(data, line); 
        else 
            is_valid_line = 0;
    }
}
	