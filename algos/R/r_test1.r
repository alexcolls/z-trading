

install.packages("leaflet")
# Load the library
library(leaflet)

# Note: if you do not already installed it, install it with:
# install.packages("leaflet")

# Background 1: NASA
m <- leaflet() %>% 
   addTiles() %>% 
   setView( lng = 2.34, lat = 48.85, zoom = 5 ) %>% 
   addProviderTiles("NASAGIBS.ViirsEarthAtNight2012")
m
 
# Background 2: World Imagery
m <- leaflet() %>% 
   addTiles() %>% 
   setView( lng = 2.34, lat = 48.85, zoom = 3 ) %>% 
   addProviderTiles("Esri.WorldImagery")
m

# save the widget in a html file if needed.
# library(htmlwidgets)
# saveWidget(m, file=paste0( getwd(), "/HtmlWidget/backgroundMapTile.html", width="1000px"))

install.packages("Rcpp")


# Libraries
library(ggplot2)
library(dplyr)
 
# Get the world polygon and extract UK
library(maps)
UK <- map_data("world") %>% filter(region=="UK")

# Get a data frame with longitude, latitude, and size of bubbles (a bubble = a city)
data <- world.cities %>% filter(country.etc=="UK")

UK

data

plot(UK)


# Left chart
ggplot() +
  geom_polygon(data = UK, aes(x=long, y = lat, group = group), fill="grey", alpha=0.3) +
  geom_point( data=data, aes(x=long, y=lat)) +
  theme_void() + ylim(50,59) + coord_map() 
 
# Second graphic with names of the 10 biggest cities
library(ggrepel)
ggplot() +
  geom_polygon(data = UK, aes(x=long, y = lat, group = group), fill="grey", alpha=0.3) +
  geom_point( data=data, aes(x=long, y=lat, alpha=pop)) +
  geom_text_repel( data=data %>% arrange(pop) %>% tail(10), aes(x=long, y=lat, label=name), size=5) +
  geom_point( data=data %>% arrange(pop) %>% tail(10), aes(x=long, y=lat), color="red", size=3) +
  theme_void() + ylim(50,59) + coord_map() +
  theme(legend.position="none")

# virids package for the color palette
library(viridis)
 
# Left: use size and color
ggplot() +
  geom_polygon(data = UK, aes(x=long, y = lat, group = group), fill="grey", alpha=0.3) +
  geom_point( data=data, aes(x=long, y=lat, size=pop, color=pop)) +
  scale_size_continuous(range=c(1,12)) +
  scale_color_viridis(trans="log") +
  theme_void() + ylim(50,59) + coord_map() 
 
# Center: reorder your dataset first! Big cities appear later = on top
data %>%
 arrange(pop) %>% 
 mutate( name=factor(name, unique(name))) %>% 
 ggplot() +
    geom_polygon(data = UK, aes(x=long, y = lat, group = group), fill="grey", alpha=0.3) +
    geom_point( aes(x=long, y=lat, size=pop, color=pop), alpha=0.9) +
    scale_size_continuous(range=c(1,12)) +
    scale_color_viridis(trans="log") +
    theme_void() + ylim(50,59) + coord_map() + theme(legend.position="none")
 
# Right: just use arrange(desc(pop)) instead
data %>%
 arrange(desc(pop)) %>% 
 mutate( name=factor(name, unique(name))) %>% 
 ggplot() +
    geom_polygon(data = UK, aes(x=long, y = lat, group = group), fill="grey", alpha=0.3) +
    geom_point( aes(x=long, y=lat, size=pop, color=pop), alpha=0.9) +
    scale_size_continuous(range=c(1,12)) +
    scale_color_viridis(trans="log") +
    theme_void() + ylim(50,59) + coord_map() + theme(legend.position="none")