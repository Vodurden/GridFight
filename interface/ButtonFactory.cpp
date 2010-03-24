#include "ButtonFactory.h"
using namespace Interface;

std::map<std::string, std::tr1::shared_ptr<sf::Image> > ButtonFactory::m_images;
std::map<std::string, Utility::fPoint> ButtonFactory::m_relativePositions;

Button* ButtonFactory::getButton(const std::string& name)
	{
	Utility::Module& module = Utility::ModuleManager::GetDefaultModule();
	const Utility::Config& conf = module.getConfigFile(module.getButtonDefinition());
	std::string lookup_type("button.");
		lookup_type += name;

	
	// Set up the Position of the Button (RELATIVE or ABSOLUTE)
	std::string positionType = conf.lookup(lookup_type + ".position.type");
	Utility::fPoint pos;
	if(positionType == "ABSOLUTE")
		{
		pos.setX(static_cast<float>(conf.lookup(lookup_type + ".position.x")));
		pos.setY(static_cast<float>(conf.lookup(lookup_type + ".position.y")));
		}
	else if(positionType == "RELATIVE")
		{
		pos = getRelativePosition(
			static_cast<const char*>(conf.lookup(lookup_type + ".position.base"))
			);
		pos = Utility::fPoint(
			static_cast<float>(conf.lookup(lookup_type + ".position.x")) + pos.getX(),
			static_cast<float>(conf.lookup(lookup_type + ".position.y")) + pos.getY()
			);
		}
	else
		{
		std::cerr << "Invalid position type: " << positionType << std::endl;
		}
	

	//Set up the visuals of the Button (IMAGE or TEXT-RECT)
	std::string visualType = conf.lookup(lookup_type + ".visual.type");
	Button* button = NULL;
	if(visualType == "IMAGE")
		{
		ImageButton* ibutton = new ImageButton(pos);

		std::string base_path = loadConfigImage("base", module, conf, lookup_type);
		std::string click_path = loadConfigImage("click", module, conf, lookup_type);
		std::string hover_path = loadConfigImage("hover", module, conf, lookup_type);

		ibutton->m_sprite_base.SetImage(*getImage(base_path));
		ibutton->m_sprite_clicked.SetImage(*getImage(click_path));
		ibutton->m_sprite_hover.SetImage(*getImage(hover_path));
		button = ibutton;
		}
	else if(visualType == "TEXT-RECT")
		{
		TextRectButton* trbutton = new TextRectButton(pos);

		//Text
		trbutton->setBorderThickness(
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.border.width")));
		
		trbutton->setTextBaseColor(
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.text.base.r")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.text.base.g")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.text.base.b")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.text.base.a"))
			);
		trbutton->setTextHoverColor(
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.text.hover.r")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.text.hover.g")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.text.hover.b")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.text.hover.a"))
			);
		trbutton->setTextClickColor(
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.text.click.r")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.text.click.g")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.text.click.b")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.text.click.a"))
			);

		// Size
		trbutton->setSize(
			static_cast<float>(conf.lookup(lookup_type + ".visual.size.w")),
			static_cast<float>(conf.lookup(lookup_type + ".visual.size.h"))
			);

		// Base Color
		trbutton->setBaseColor(
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.rect.base.r")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.rect.base.g")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.rect.base.b")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.rect.base.a"))
			);
		trbutton->setHoverColor(
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.rect.hover.r")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.rect.hover.g")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.rect.hover.b")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.rect.hover.a"))
			);
		trbutton->setClickColor(
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.rect.click.r")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.rect.click.g")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.rect.click.b")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.rect.click.a"))
			);
		
		//Border Color
		trbutton->setBorderBaseColor(
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.border.base.r")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.border.base.g")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.border.base.b")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.border.base.a"))
			);
		trbutton->setBorderHoverColor(
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.border.hover.r")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.border.hover.g")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.border.hover.b")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.border.hover.a"))
			);
		trbutton->setBorderClickColor(
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.border.click.r")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.border.click.g")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.border.click.b")),
			static_cast<int>(conf.lookup(lookup_type + ".visual.color.border.click.a"))
			);

		trbutton->setText(static_cast<const char*>(conf.lookup(lookup_type + ".visual.text")));
		trbutton->setTextSize(static_cast<float>(conf.lookup(lookup_type + ".visual.color.text.size")));

		button = trbutton;
		}
	else
		{
		std::cerr << "Invalid visual type: " << visualType << std::endl;
		}
	return button;
	}

void ButtonFactory::loadImage(const std::string& path)
	{
	if(m_images.find(path) == m_images.end())
		{
		std::tr1::shared_ptr<sf::Image> ptr(new sf::Image);
		m_images[path] = ptr;
		m_images[path]->LoadFromFile(path);
		}
	}

std::string ButtonFactory::loadConfigImage(
	const std::string& name, 
	Utility::Module& module, 
	const Utility::Config& conf,
	const std::string& lookup_type)
	{
	
	std::string path = module.getRelativePath() +
		"/" + static_cast<const char*>(conf.lookup(lookup_type + ".visual." + name));

#ifndef NDEBUG
	std::cerr << "Loading image: " << path << std::endl;
	assert(boost::filesystem::exists(path));
#endif

	loadImage(path);
	return path;
	}

void ButtonFactory::addRelativePosition(const std::string& name, Utility::fPoint point)
	{
	if(m_relativePositions.find(name) != m_relativePositions.end())
		{
		std::cerr << "Overwriting point [" << name << "](" << 
			m_relativePositions[name].getX() << ", " << m_relativePositions[name].getY() << ") with point: (" << 
			point.getX() << ", " << point.getY() << ")" << std::endl;
		}
	m_relativePositions[name] = point;
	}

Utility::fPoint ButtonFactory::getRelativePosition(const std::string& name)
	{
	if(m_relativePositions.find(name) != m_relativePositions.end())
		{
		return m_relativePositions[name];
		}
	else
		{
		std::cerr << "Invalid relative position: " << name << std::endl;
		return Utility::fPoint(0.0f, 0.0f);
		}
	}

std::tr1::shared_ptr<sf::Image> ButtonFactory::getImage(const std::string& name)
	{
	return m_images[name];
	}

